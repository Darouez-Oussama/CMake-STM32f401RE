cmake_minimum_required(VERSION 3.15)
project(MySTM32F401Project C ASM)

set(EXECUTABLE ${PROJECT_NAME}.elf)
set(CPU_FLAGS -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard)
set(LINKER_SCRIPT "../linker.ld")

include_directories(
    Drivers/CMSIS/Include
    Drivers/CMSIS/Device/ST/STM32F4xx/cmsis-device-f4/Include
    Drivers/STM32F4xx_HAL_Driver/stm32f4xx-hal-driver/Inc
)

file(GLOB HAL_SOURCES Drivers/STM32F4xx_HAL_Driver/stm32f4xx-hal-driver/Src/*.c)
set(SOURCES
    src/main.c
    src/startup.c  
    Drivers/CMSIS/Device/ST/STM32F4xx/cmsis-device-f4/Source/Templates/system_stm32f4xx.c
    ${HAL_SOURCES}  
)

add_executable(${EXECUTABLE} ${SOURCES})
target_compile_definitions(${EXECUTABLE} PRIVATE STM32F401xE)  
target_compile_options(${EXECUTABLE} PRIVATE ${CPU_FLAGS} -Wall -O0 -g)
target_link_options(${EXECUTABLE} PRIVATE -T ${LINKER_SCRIPT} ${CPU_FLAGS} -Wl,--gc-sections -Wl,-Map=${PROJECT_NAME}.map)

# Post-build step to generate .bin file
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin
    COMMENT "Generating binary file: ${PROJECT_NAME}.bin"
)