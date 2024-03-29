//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wago Modbus Tango Server
//  @ File Name : ModbusAbstract.h
//  @ Date : 2013-02-03
//  @ Author : Pawel Kowaliszyn
//
//


#if !defined(_MODBUSABSTRACT_H)
#define _MODBUSABSTRACT_H

#include <vector>
#include <string>

/* Pure abstract class interfacing modbus protocol layer. Interface object to modbus protocol
 * should derive from this class and provide acces to modbus through methods deriving from
 * abstract methods of this class.
 *
 */
class ModbusAbstract
{
public:
	/*!Abstract method representing Read Discrete Inputs modbus service.
	 *
	 * \param addr			modbus start addres of read.
	 * \param numOfInputs	number of inputs to be read.
	 * \param dataBuffer	reference to placeholder for values read from device.
	 *
	 * \return service status;
	 */
	virtual int ReadDigitalInputs(unsigned int addr, unsigned int numOfInputs, std::vector<unsigned short>& dataBuffer) = 0;

	/*!Abstract method representing Read Input Registers modbus service.
	 *
	 * \param addr			modbus start addres of read.
	 * \param numOfRegisters	number of input registers to be read.
	 * \param dataBuffer	reference to placeholder for values read from device.
	 *
	 * \return service status;
	 */
	virtual int ReadInputRegisters(unsigned int addr, unsigned int numOfRegisters, std::vector<unsigned short>& dataBuffer) = 0;

	/*!Abstract method representing Read Holding Registers modbus service.
	 *
	 * \param addr			modbus start addres of read.
	 * \param numOfRegisters	number of holding registers to be read.
	 * \param dataBuffer	reference to placeholder for values read from device.
	 *
	 * \return service status;
	 */
	virtual int ReadHoldingRegisters(unsigned int addr, unsigned int numOfRegisters, std::vector<unsigned short>& dataBuffer) = 0;

	/*!Abstract method representing Read Coils modbus service.
	 *
	 * \param addr			modbus start addres of read.
	 * \param numOfCoils	number of coils to be read.
	 * \param dataBuffer	reference to placeholder for values read from device.
	 *
	 * \return service status;
	 */
	virtual int ReadMultipleCoilsStatus(unsigned int addr,unsigned int numOfCoils, std::vector<unsigned short>& dataBuffer) = 0;

	/*!Abstract method representing Write Multiple Coils modbus service.
	 *
	 * \param addr		modbus start addres for write.
	 * \param values	reference to vector of values to be written.
	 *
	 * \return service status;
	 */
	virtual int ForceMultipleCoils(unsigned int addr, std::vector<unsigned short>& values) = 0;

	/*!Abstract method representing Write Multiple Registers modbus service.
	 *
	 * \param addr		modbus start addres for write.
	 * \param values	reference to vector of values to be written.
	 *
	 * \return service status;
	 */
	virtual int PresetMultipleRegisters(unsigned int addr, std::vector<unsigned short>& values) = 0;

	/*!Abstract method representing Write single register modbus service.
	 *
	 * \param addr		modbus start addres for write.
	 * \param value		value to be written.
	 *
	 * \return service status;
	 */
	virtual int PresetSingleRegister(unsigned int addr, unsigned short value) = 0;

	/*!Abstract method for checking validity of of modbus connection.
	 *
	 *  \return true if state of modbus connection is invalid, false if state is valid.
	 */
	virtual bool ModbusStateCheck()=0;

	/*!Abstract method which throws last exception cached on modbus interface.
	 */
	virtual void RaiseLastModbusException()=0;

	/*!This method is used by upper layer to signal modbus layer that process image
	 * structure configured in device representation is incosistent with image
	 * on modbus device.
	 */
	virtual void InconsistentImageFault(std::string desc = std::string("Modbus::error_read"))= 0;

	/*!This method is used by upper layer to signal modbus layer that device representation´s
	 * process image is consistent with image on modbus device.
	 */
	virtual void ImageConsistent()=0;


	/*!Abstract method for locking thread acces to modbus interface (to provide thread safety).
	 */
	virtual void LockAccess()=0;

	/*!Abstract method for unlocking thread acces to modbus interface (to provide thread safety).
	 */
	virtual void UnlockAccess()=0;

};

#endif  //_MODBUSABSTRACT_H
