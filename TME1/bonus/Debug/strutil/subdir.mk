################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../strutil/strutil.cpp 

CPP_DEPS += \
./strutil/strutil.d 

OBJS += \
./strutil/strutil.o 


# Each subdirectory must supply rules for building sources it contributes
strutil/%.o: ../strutil/%.cpp strutil/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-strutil

clean-strutil:
	-$(RM) ./strutil/strutil.d ./strutil/strutil.o

.PHONY: clean-strutil

