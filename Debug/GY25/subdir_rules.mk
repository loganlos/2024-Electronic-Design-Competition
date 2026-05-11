################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
GY25/%.o: ../GY25/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia141/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving" -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving/Control" -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving/CCD" -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving/GY25" -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving/Encoder" -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving/sys" -I"C:/Users/LoganLos/workspace_ccstheia/Automatic_Driving/Debug" -I"C:/ti/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"GY25/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


