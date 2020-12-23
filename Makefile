FLAGS_D=-fno-stack-protector -m32 -z execstack -Wl,-z,norelro -g -no-pie 
FLAGS= -m32 -g
EXEC=simple_login simple_login_s simple_stack
BUILD=build

all: 
	mkdir -p build
	make $(EXEC)

simple_stack:simple_stack.c
	gcc $? -o $(BUILD)/$@ $(FLAGS_D)

simple_login:simple_login.c
	gcc $? -o $(BUILD)/$@ $(FLAGS_D)

simple_login_s:simple_login.c
	gcc $? -o $(BUILD)/$@ $(FLAGS)

.PHONY: all clean

clean:
	rm -rf $(BUILD)
