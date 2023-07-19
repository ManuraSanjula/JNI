################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/access_fields.cpp \
../src/airy_func.cpp \
../src/call_constructor.cpp \
../src/call_generics_method.cpp \
../src/call_inner_classes.cpp \
../src/call_interface_method.cpp \
../src/call_nonvirtual_method.cpp \
../src/call_reflection.cpp \
../src/call_static_methods.cpp \
../src/constants_values.cpp \
../src/file_reader.cpp \
../src/file_reader2.cpp \
../src/generic_classes.cpp \
../src/global_caching.cpp \
../src/id_caching.cpp \
../src/inner_class.cpp \
../src/method_invokation.cpp \
../src/method_local_inner_class.cpp \
../src/native_c.cpp \
../src/object_arrays.cpp \
../src/override.cpp \
../src/primitives.cpp \
../src/pritimive_arrays.cpp \
../src/set_fields.cpp \
../src/static_fields.cpp \
../src/string_c.cpp 

OBJS += \
./src/access_fields.o \
./src/airy_func.o \
./src/call_constructor.o \
./src/call_generics_method.o \
./src/call_inner_classes.o \
./src/call_interface_method.o \
./src/call_nonvirtual_method.o \
./src/call_reflection.o \
./src/call_static_methods.o \
./src/constants_values.o \
./src/file_reader.o \
./src/file_reader2.o \
./src/generic_classes.o \
./src/global_caching.o \
./src/id_caching.o \
./src/inner_class.o \
./src/method_invokation.o \
./src/method_local_inner_class.o \
./src/native_c.o \
./src/object_arrays.o \
./src/override.o \
./src/primitives.o \
./src/pritimive_arrays.o \
./src/set_fields.o \
./src/static_fields.o \
./src/string_c.o 

CPP_DEPS += \
./src/access_fields.d \
./src/airy_func.d \
./src/call_constructor.d \
./src/call_generics_method.d \
./src/call_inner_classes.d \
./src/call_interface_method.d \
./src/call_nonvirtual_method.d \
./src/call_reflection.d \
./src/call_static_methods.d \
./src/constants_values.d \
./src/file_reader.d \
./src/file_reader2.d \
./src/generic_classes.d \
./src/global_caching.d \
./src/id_caching.d \
./src/inner_class.d \
./src/method_invokation.d \
./src/method_local_inner_class.d \
./src/native_c.d \
./src/object_arrays.d \
./src/override.d \
./src/primitives.d \
./src/pritimive_arrays.d \
./src/set_fields.d \
./src/static_fields.d \
./src/string_c.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I/Library/Java/JavaVirtualMachines/jdk1.8.0_144.jdk/Contents/Home/include -I/Library/Java/JavaVirtualMachines/jdk1.8.0_144.jdk/Contents/Home/include/darwin -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


