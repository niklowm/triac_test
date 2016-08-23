

#include "mlx90614.h"

void mlx90614_init(MLX90614_t* device/*, todo: twi device*/, uint8_t device_address)
{
  // todo: twi device...
  
  // device address...
  // todo: check address or mask!?
  device->device_address = device_address;
}

// todo: init check function to use during debug at least!?

uint32_t mlx90614_read_id(MLX90614_t* device);

uint16_t mlx90614_read_object_temp_raw(MLX90614_t* device);
uint16_t mlx90614_read_object_temp_fahrenheit(MLX90614_t* device);
uint16_t mlx90614_read_object_temp_celsius(MLX90614_t* device);

uint16_t mlx90614_read_ambient_temp_raw(MLX90614_t* device);
uint16_t mlx90614_read_ambient_temp_fahrenheit(MLX90614_t* device);
uint16_t mlx90614_read_ambient_temp_celsius(MLX90614_t* device);
