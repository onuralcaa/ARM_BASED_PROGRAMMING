[#ftl]
[#compress]
[#assign threadControlBlock = "NULL"]
[#assign mutexControl       = "NULL"]
[#assign timerControlBlock  = "NULL"]
[#assign queueControlBlock  = "NULL"]
[#assign semaphoreControl   = "NULL"]
[#assign nbThreads = 0]
[#assign useMPU = "0"]
[#assign familyName=FamilyName?lower_case]

[#list SWIPdatas as SWIP]
  [#if SWIP.defines??]
    [#list SWIP.defines as definition]
      [#if definition.name=="USE_MPU"]
        [#assign useMPU = definition.value]
      [/#if]
     [/#list]
  [/#if]
[/#list]

[#if useMPU == "1"]  [#-- Defines for STM32XX (from yy board) --]
/* USER CODE BEGIN SETTINGS_MPU */
/* put here the regions for the right series (from the right boarD) */
/* USER CODE END SETTINGS_MPU */
[/#if]

[#list SWIPdatas as SWIP]
  [#if SWIP.variables??]
    [#list SWIP.variables as variable]
      [#if variable.name=="Threads"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign threadName = i]
          [/#if]
          [#if index == 1]
            [#assign threadPriority = i]
          [/#if]
          [#if index == 2]
            [#assign threadStackSize = i]
          [/#if]
          [#if index == 3]
            [#assign threadFunction = i]
          [/#if]
          [#if index == 4]
            [#assign generateFunction = i]
          [/#if]
          [#if index == 5]
            [#assign codegenOption = i]
          [/#if]
          [#if index == 6]
            [#assign threadArguments = i]
          [/#if] 
          [#if index == 7]
            [#assign threadAllocation = i]
          [/#if]
          [#if index == 8]
            [#assign threadBuffer = i]
          [/#if]
          [#if index == 9]
            [#assign threadControlBlock = i]
          [/#if]
          [#assign index = index + 1]
        [/#list]
        [#assign nbThreads = nbThreads + 1]

        TaskHandle_t ${threadName}Handle;
        [#if threadControlBlock != "NULL"]
          [#-- /* Buffer that the task being created will use as its stack. */ --]
          StackType_t ${threadBuffer}[ ${threadStackSize} ];
          [#-- /* Structure that will hold the TCB of the task being created. */ --]
          StaticTask_t ${threadControlBlock};
        [/#if]
      [/#if]

      [#if variable.name=="Mutexes"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign mutexName = i]
          [/#if]
          [#if index == 1]
            [#assign mutexAllocation = i]
          [/#if]
          [#if index == 2]
            [#assign mutexControl = i]
          [/#if]
          [#assign index = index + 1]
        [/#list]
        [#if mutexName != "0"]
          SemaphoreHandle_t ${mutexName}Handle;
          [#if mutexControl != "NULL"]
            StaticSemaphore_t ${mutexControl};
          [/#if]
        [/#if]
      [/#if]

      [#if variable.name=="RecursiveMutexes"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign mutexName = i]
          [/#if]
          [#if index == 1]
            [#assign mutexAllocation = i]
          [/#if]
          [#if index == 2]
            [#assign mutexControl = i]
          [/#if]
          [#assign index = index + 1]
        [/#list]
        [#if mutexName != "0"]
          SemaphoreHandle_t ${mutexName}Handle; 
          [#if mutexControl != "NULL"]
            StaticSemaphore_t ${mutexControl};
          [/#if]
        [/#if]
      [/#if]

      [#if variable.name=="Timers"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign timerName = i]
          [/#if]
          [#if index == 1]
            [#assign timerCallback = i]
          [/#if]
          [#if index == 2]
            [#assign timerType = i]
          [/#if]
          [#if index == 3]
            [#assign generateCallback = i]
          [/#if]
          [#if index == 4]
            [#assign timerCodeGen = i]
          [/#if]
          [#if index == 5]
            [#assign timerParameters = i]
          [/#if]
          [#if index == 6]
            [#assign timerAllocation = i]
          [/#if]
          [#if index == 7]
            [#assign timerControlBlock = i]
          [/#if]
          [#assign index = index + 1]
        [/#list]
        [#if timerName != "0"]
          TimerHandle_t ${timerName}Handle;
          [#if timerControlBlock != "NULL"]
            StaticTimer_t ${timerControlBlock};
          [/#if]
        [/#if]  
      [/#if]

      [#if variable.name=="Queues"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign queueName = i]
          [/#if]
          [#if index == 1]
            [#assign queueSize = i]
          [/#if]
          [#if index == 2]
            [#assign queueElementType = i]
          [/#if]
          [#if index == 3]
            [#assign queueIsIntegerType = i]
          [/#if]
          [#if index == 4]
            [#assign queueAllocation = i]
          [/#if]
          [#if index == 5]
            [#assign queueBuffer = i]
          [/#if]
          [#if index == 6]
            [#assign queueControlBlock = i]
          [/#if] 
          [#assign index = index + 1]
        [/#list] 
        [#if queueName != "0"]
          QueueHandle_t ${queueName}Handle;
          [#if queueControlBlock != "NULL"]
           [#if queueIsIntegerType = "0"]
           uint8_t ${queueBuffer}[ ${queueSize} * sizeof( ${queueElementType} ) ];
           [#else]
           uint8_t ${queueBuffer}[ ${queueSize} * ${queueElementType} ];
           [/#if]
           StaticQueue_t ${queueControlBlock};
          [/#if]
        [/#if]  
      [/#if]

      [#if variable.name=="Semaphores"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign semaphoreName = i]
          [/#if]
          [#if index == 2]
            [#assign semaphoreAllocation = i]
          [/#if]
          [#if index == 3]
            [#assign semaphoreControl = i]
          [/#if]
          [#assign index = index + 1]
        [/#list]
        [#if semaphoreName != "0"]
          SemaphoreHandle_t ${semaphoreName}Handle;
          [#if semaphoreControl != "NULL"]
            StaticSemaphore_t ${semaphoreControl};
          [/#if]
        [/#if]
      [/#if]

      [#if variable.name=="BinarySemaphores"]
        [#assign s = variable.valueList]
        [#assign index = 0]
        [#list s as i]
          [#if index == 0]
            [#assign semaphoreName = i]
          [/#if]
          [#if index == 1]
            [#assign semaphoreAllocation = i]
          [/#if]
          [#if index == 2]
            [#assign semaphoreControl = i]
          [/#if]
          [#assign index = index + 1]
        [/#list]
        [#if semaphoreName != "0"]
          SemaphoreHandle_t ${semaphoreName}Handle;
          [#if semaphoreControl != "NULL"]
            StaticSemaphore_t ${semaphoreControl};
          [/#if]
        [/#if]
      [/#if]
    [/#list]

  [/#if]
[/#list]
[/#compress]
