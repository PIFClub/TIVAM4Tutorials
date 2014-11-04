################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/UNGDUNG/CCS/Caidat/ccsv6/tools/compiler/arm_5.1.8

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"../tm4c123gh6pm.cmd" \
-l"libc.a" \
-l"C:\ti\TivaWare_C_Series-1.1\driverlib\ccs\Debug\driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TIVAM4_TUT_UART_UsingInterrupts.out \

EXE_OUTPUTS__QUOTED += \
"TIVAM4_TUT_UART_UsingInterrupts.out" \

BIN_OUTPUTS += \
TIVAM4_TUT_UART_UsingInterrupts.hex \

BIN_OUTPUTS__QUOTED += \
"TIVAM4_TUT_UART_UsingInterrupts.hex" \


# All Target
all: TIVAM4_TUT_UART_UsingInterrupts.out

# Tool invocations
TIVAM4_TUT_UART_UsingInterrupts.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"D:/UNGDUNG/CCS/Caidat/ccsv6/tools/compiler/arm_5.1.8/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off -z -m"TIVAM4_TUT_UART_UsingInterrupts.map" --heap_size=0 --stack_size=512 -i"D:/UNGDUNG/CCS/Caidat/ccsv6/tools/compiler/arm_5.1.8/lib" -i"D:/UNGDUNG/CCS/Caidat/ccsv6/tools/compiler/arm_5.1.8/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="TIVAM4_TUT_UART_UsingInterrupts_linkInfo.xml" --rom_model -o "TIVAM4_TUT_UART_UsingInterrupts.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

TIVAM4_TUT_UART_UsingInterrupts.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"D:/UNGDUNG/CCS/Caidat/ccsv6/tools/compiler/arm_5.1.8/bin/armhex"  -o "TIVAM4_TUT_UART_UsingInterrupts.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.pp" "tm4c123gh6pm_startup_ccs.pp" 
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

