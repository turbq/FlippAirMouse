#include "imu.h"

bool imu_begin() {
    furi_hal_i2c_acquire(&furi_hal_i2c_handle_external);
    bool ret = lsm6dso_begin(); // lsm6ds3trc_begin();
    furi_hal_i2c_release(&furi_hal_i2c_handle_external);
    return ret;
}

void imu_end() {
    furi_hal_i2c_acquire(&furi_hal_i2c_handle_external);
    lsm6dso_end();
    furi_hal_i2c_release(&furi_hal_i2c_handle_external);
}

int imu_read(double* vec) {
    furi_hal_i2c_acquire(&furi_hal_i2c_handle_external);
    int ret = lsm6dso_read(vec); // lsm6ds3trc_read(vec);
    furi_hal_i2c_release(&furi_hal_i2c_handle_external);
    return ret;
}

void imu_scan_i2c() {
    unsigned int address;
    unsigned int *found;
    for(address = 1; address < 0xff; address++) {
        if(furi_hal_i2c_is_device_ready(&furi_hal_i2c_handle_external, address, 50)) {
            FURI_LOG_E(IMU_TAG, "<<<<<<<found Device>>>>>>> ID 0x%X", address);
        }
    }
}
