#ifndef IMU_LSM6DS3TRC_H
#define IMU_LSM6DS3TRC_H

#include "../../lib/lsm6ds3tr-api/lsm6ds3tr-c_reg.h"

#include <furi_hal.h>

#include "imu.h"

// External variable declaration
extern stmdev_ctx_t lsm6ds3trc_ctx;

// Function declarations
int32_t lsm6ds3trc_write_i2c(void* handle, uint8_t reg_addr, const uint8_t* data, uint16_t len);
int32_t lsm6ds3trc_read_i2c(void* handle, uint8_t reg_addr, uint8_t* read_data, uint16_t len);
bool lsm6ds3trc_begin(void);
void lsm6ds3trc_end(void);
int lsm6ds3trc_read(double* vec);

extern struct imu_t imu_lsm6ds3trc;

#endif // LSM6DS3TRC_H