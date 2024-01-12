/*
 * iec101_arm_port.c
 *
 *  Created on: Nov 22, 2023
 *      Author: yasko
 */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "stm32f4xx_hal.h"

#include "lib_memory.h"

#include "hal_serial.h"
#include "hal_time.h"
#include "hal_thread.h"

extern UART_HandleTypeDef huart2;

uint8_t buf_rx[1];
uint8_t out_rx[1];
uint64_t bytesRead_rx = 0;
uint64_t numberOfBytesWritten = 0;
bool status_rx;
bool status_tx;
__IO uint32_t millis;
__IO uint32_t nanos;

struct sSerialPort {
	char interfaceName[100];
	int comPort;
	int baudRate;
	uint8_t dataBits;
	char parity;
	uint8_t stopBits;
	uint64_t lastSentTime;
	int timeout;
	SerialPortError lastError;
};
//SerialPort self
//UART_HandleTypeDef* modbusUart

__STATIC_INLINE void DelayMicro(__IO uint32_t micros)
{
	micros *=(SystemCoreClock / 1000000)/5 ;
	while (micros--);
}
//---

msSinceEpoch Hal_getTimeInMs()
{
//    struct timeval now;

//    gettimeofday(&now, NULL);
	millis =millis + (SystemCoreClock / 1000)/5 ;

    return millis;
}

nsSinceEpoch
Hal_getTimeInNs()
{
//    struct timespec now;

//    clock_gettime(CLOCK_REALTIME, &now);

	nanos  =nanos + (SystemCoreClock / 1000000000)/5 ;

    return nanos;
}


SerialPort
SerialPort_create(const char* interfaceName, int baudRate, uint8_t dataBits, char parity, uint8_t stopBits)
{
	SerialPort self = (SerialPort)GLOBAL_MALLOC(sizeof(struct sSerialPort));

	if (self != NULL) {
		self->comPort = NULL;
		self->baudRate = baudRate;
		self->dataBits = dataBits;
		self->stopBits = stopBits;
		self->parity = parity;
		self->lastSentTime = 0;
		self->timeout = 100; /* 100 ms */
		strncpy(self->interfaceName, interfaceName, 100);
		self->lastError = SERIAL_PORT_ERROR_NONE;
	}

	return self;
}

int SerialPort_readByte(SerialPort self)
{
	bytesRead_rx = 0;

	status_rx = !(HAL_UART_Receive_IT(&huart2, buf_rx, 1));

	if (status_rx == false) {
		self->lastError = SERIAL_PORT_ERROR_UNKNOWN;
		return -1;
	}
	else
	{
		bytesRead_rx = bytesRead_rx + 1;
	}

	self->lastError = SERIAL_PORT_ERROR_NONE;

	if (bytesRead_rx == 0)
		return -1;
	else
	{
		out_rx[0] =  buf_rx[0];
		buf_rx[0] = 0;
		return (int) out_rx[0];
	}
}

int
SerialPort_write(SerialPort self, uint8_t* buffer, int startPos, int bufSize)
{
	//TODO assure minimum line idle time
	numberOfBytesWritten = 0;
    self->lastError = SERIAL_PORT_ERROR_NONE;

    status_tx =  !(HAL_UART_Transmit_IT(&huart2, buffer + startPos, bufSize));

//			WriteFile(self->comPort, buffer + startPos, bufSize, &numberOfBytesWritten, NULL);

	if (status_tx == false) {
	    self->lastError = SERIAL_PORT_ERROR_UNKNOWN;
	    return -1;
	}
	else
	{
		numberOfBytesWritten = numberOfBytesWritten + 1;
	}
//	status = FlushFileBuffers(self->comPort);

	if (status_tx == false) {
		printf("FlushFileBuffers failed!\n");
	}

//	self->lastSentTime = Hal_getTimeInMs();

	return (int) numberOfBytesWritten;
}

struct sThread {
   ThreadExecutionFunction function;
   void* parameter;
   pthread_t pthread;
   int state;
   bool autodestroy;
};

typedef struct sSemaphore* mSemaphore;

struct sSemaphore
{
    pthread_mutex_t mutex;
};

/*
 * NOTE: initialValue is ignored because semaphore was replaced by mutex
 */
Semaphore
Semaphore_create(int initialValue)
{
    mSemaphore self = NULL;

    self = (mSemaphore) GLOBAL_CALLOC(1, sizeof(struct sSemaphore));

//    if (self) {
//        pthread_mutex_init(&(self->mutex), NULL);
//    }

    return (Semaphore)self;
}

/* lock mutex */
void
Semaphore_wait(Semaphore self)
{
    mSemaphore mSelf = (mSemaphore) self;

    int retVal = 0;

    if (retVal) {
       printf("FATAL ERROR: pthread_mutex_lock failed (err=%i)\n", retVal);
       exit(-1);
    }
}

/* unlock mutex */
void
Semaphore_post(Semaphore self)
{
    mSemaphore mSelf = (mSemaphore) self;

    int retVal = 0;

    if (retVal) {
        printf("FATAL ERROR: pthread_mutex_unlock failed (err=%i)\n", retVal);
        exit(-1);
    }
}

void
Semaphore_destroy(Semaphore self)
{
    if (self) {
        mSemaphore mSelf = (mSemaphore) self;

//        pthread_mutex_destroy(&(mSelf->mutex));

        GLOBAL_FREEMEM(mSelf);
    }
}

Thread
Thread_create(ThreadExecutionFunction function, void* parameter, bool autodestroy)
{
   Thread thread = (Thread) GLOBAL_MALLOC(sizeof(struct sThread));

   if (thread != NULL) {
        thread->parameter = parameter;
        thread->function = function;
        thread->state = 0;
        thread->autodestroy = autodestroy;
   }

   return thread;
}

static void*
destroyAutomaticThread(void* parameter)
{
    Thread thread = (Thread) parameter;

    thread->function(thread->parameter);

    GLOBAL_FREEMEM(thread);

    pthread_exit(NULL);
}

void
Thread_start(Thread thread)
{
   if (thread->autodestroy == true) {
       pthread_create(&thread->pthread, NULL, destroyAutomaticThread, thread);
       pthread_detach(thread->pthread);
   }
   else
       pthread_create(&thread->pthread, NULL, thread->function, thread->parameter);

   thread->state = 1;
}

void
Thread_destroy(Thread thread)
{
   if (thread->state == 1) {
       pthread_join(thread->pthread, NULL);
   }

   GLOBAL_FREEMEM(thread);
}

void
Thread_sleep(int millies)
{
   HAL_Delay(millies * 1000);
//   usleep(millies * 1000);
}
