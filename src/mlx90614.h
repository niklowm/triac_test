
#ifndef MLX90614_H
#define MLX90614_H

// todo: support multiple devices!?

// Defines...
//************
#define MLX90614_ADDR_BASE 0x5A

// RAM
#define MLX90614_RAWIR1     0x04
#define MLX90614_RAWIR2     0x05
#define MLX90614_TA         0x06
#define MLX90614_TOBJ1      0x07
#define MLX90614_TOBJ2      0x08

// EEPROM
#define MLX90614_TOMAX      0x20
#define MLX90614_TOMIN      0x21
#define MLX90614_PWMCTRL    0x22
#define MLX90614_TARANGE    0x23
#define MLX90614_EMISS      0x24
#define MLX90614_CONFIG     0x25
#define MLX90614_ADDR       0x0E
#define MLX90614_ID1        0x3C
#define MLX90614_ID2        0x3D
#define MLX90614_ID3        0x3E
#define MLX90614_ID4        0x3F


// Type Defs...
//**************
typedef struct
{
  // todo: twi device...
  uint8_t device_address; // i2c device address...
}MLX90614_t;


// todo: what's needed? twi if, address...
void mlx90614_init(MLX90614_t* device/*, todo: twi device*/, uint8_t device_address);

uint32_t mlx90614_read_id(MLX90614_t* device);

uint16_t mlx90614_read_object_temp_raw(MLX90614_t* device);
uint16_t mlx90614_read_object_temp_fahrenheit(MLX90614_t* device);
uint16_t mlx90614_read_object_temp_celsius(MLX90614_t* device);

uint16_t mlx90614_read_ambient_temp_raw(MLX90614_t* device);
uint16_t mlx90614_read_ambient_temp_fahrenheit(MLX90614_t* device);
uint16_t mlx90614_read_ambient_temp_celsius(MLX90614_t* device);


#endif // MLX90614_H
