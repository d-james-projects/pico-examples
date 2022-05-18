add_executable(david_gpio_irq)

target_sources(david_gpio_irq PRIVATE
        david_gpio_irq.cpp
        RotaryEncoder.cpp
        RotaryEncoder.h
        )

# pull in common dependencies
target_link_libraries(david_gpio_irq PRIVATE pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(david_gpio_irq 1)
pico_enable_stdio_uart(david_gpio_irq 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(david_gpio_irq)

# add url via pico_set_program_url
example_auto_set_url(david_gpio_irq)
