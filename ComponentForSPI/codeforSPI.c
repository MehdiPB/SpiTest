#include "legato.h"
#include "interfaces.h"


uint8_t write_buf[] ={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
//uint8_t read_buf[sizeof(write_buf)] = "1a1a1" ;

COMPONENT_INIT
{
    le_spi_DeviceHandleRef_t spiHandle;
    le_result_t res;
    //size_t read_buf_size;

    LE_INFO("# ==== START: spiTest app ==== ");
    LE_INFO("Opening SPI file handle");

    res = le_spi_Open("spidev1.0", &spiHandle);
    if ( res != LE_OK )
    {
        LE_ERROR("le_spi_Open failed: Result = %s", LE_RESULT_TXT(res) );
        exit(res);
    }
    else
    {
        LE_INFO("le_spi_Open sucess");
    }

    LE_INFO("Configuring SPI");
    le_spi_Configure(spiHandle,0, 8, 960000, 0); // 3=mode, 8=bits dans la trame, 1000000=speed, 0=msb


    res = le_spi_WriteHD(spiHandle, write_buf, 5); //nombre des bytes
    if ( res == LE_OK )
    {
        LE_INFO("SEND OKKKKKKKKKKKKKKKKKKKK" );
        exit(res);
    }
    LE_FATAL_IF(res != LE_OK, "le_spi_WriteHD failed with result=%s", LE_RESULT_TXT(res));

    exit(res);

}
