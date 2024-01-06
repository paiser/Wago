/*----- PROTECTED REGION ID(Wago.h) ENABLED START -----*/
//=============================================================================
//
// file :        Wago.h
//
// description : Include file for the Wago class
//
// project :     Wago controller interface
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author: kowalisz $
//
// $Revision: 1.10 $
// $Date: 2013-09-04 16:10:23 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef Wago_H
#define Wago_H

#include <tango.h>

#include "./core_src/WagoDevice.h"
#include "ModbusConn.h"

/*----- PROTECTED REGION END -----*/	//	Wago.h

#ifdef TANGO_LOG
	// cppTango after c934adea (Merge branch 'remove-cout-definition' into 'main', 2022-05-23)
	// nothing to do
#else
	// cppTango 9.3-backports and older
	#define TANGO_LOG       cout
	#define TANGO_LOG_INFO  cout2
	#define TANGO_LOG_DEBUG cout3
#endif // TANGO_LOG

/**
 *  Wago class description:
 *    Device server for Wago 750 series Programable Fieldbus Controllers 
 *    and Fieldbus Couplers. The class supports reading and writing to a node
 *    consisting of a number of Wago modules. It communicates with device over
 *    Modbus TCP or RTU protocol by means of Modbus Tango class.
 */


namespace Wago_ns
{
/*----- PROTECTED REGION ID(Wago::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations
/*----- PROTECTED REGION END -----*/	//	Wago::Additional Class Declarations

class Wago : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(Wago::Data Members) ENABLED START -----*/

//	Add your own data members
private:
	WagoDevice*  wd;	//Pointer to wago device object.
	DeviceState* mbDevState; //Holder of wago device state.
/*----- PROTECTED REGION END -----*/	//	Wago::Data Members

//	Device property data members
public:
	//	modbusDevName:	Name of Modbus tango device server used for communication with
	//   physical device.
	std::string	modbusDevName;
	//	config:	Configuration of physical modules in device and its projection
	//   to LogicalDevices in server.
	std::vector<std::string>	config;
	//	updatePeriod:	Modbus process image cache update interval.
	Tango::DevUShort	updatePeriod;


//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Wago(Tango::DeviceClass *cl,std::string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Wago(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	Wago(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~Wago();


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : Wago::read_attr_hardware()
	 * Description:  Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(std::vector<long> &attr_list);


	//--------------------------------------------------------
	/**
	 *	Method      : Wago::add_dynamic_attributes()
	 * Description:  Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command State related method
	 * Description:  This command gets the device state (stored in its device_state data member) and returns it to the caller.
	 *
	 *	@returns Device state
	 */
	virtual Tango::DevState dev_state();
	/**
	 *	Command Status related method
	 * Description:  This command gets the device status (stored in its device_status data member) and returns it to the caller.
	 *
	 *	@returns Device status
	 */
	virtual Tango::ConstDevString dev_status();
	/**
	 *	Command DevReadNoCachePhys related method
	 * Description:  Read all physical values of the specified logical device and 
	 *               //              return the values as a float array. Physical value are
	 *               //              calculated from module registers according to a predefined
	 *               //              algorithm deduced from the module type in the catalogue.
	 *               //              Read registers from the cache.
	 *               //
	 *               //              Note: not all the channels of the logical device are
	 *               //              returned but only the ones on modules marked as specials
	 *               //              in the catalogue.
	 *
	 *	@param argin Logical device index.
	 *	@returns Array of values.
	 */
	virtual Tango::DevVarFloatArray *dev_read_no_cache_phys(Tango::DevShort argin);
	virtual bool is_DevReadNoCachePhys_allowed(const CORBA::Any &any);
	/**
	 *	Command DevWritePhys related method
	 *
	 *
	 *	@param argin Logical device key and values for write
	 */
	virtual void dev_write_phys(const Tango::DevVarFloatArray *argin);
	virtual bool is_DevWritePhys_allowed(const CORBA::Any &any);
	/**
	 *	Command DevReadPhys related method
	 * Description:  Read physical values of LD
	 *
	 *	@param argin Logical device key
	 *	@returns Placeholder for obtained values
	 */
	virtual Tango::DevVarFloatArray *dev_read_phys(Tango::DevShort argin);
	virtual bool is_DevReadPhys_allowed(const CORBA::Any &any);
	/**
	 *	Command DevWriteDigi related method
	 * Description:  Write words and bits to output module registers.
	 *
	 *	@param argin Logical device key, then pairs of channel,value.
	 */
	virtual void dev_write_digi(const Tango::DevVarShortArray *argin);
	virtual bool is_DevWriteDigi_allowed(const CORBA::Any &any);
	/**
	 *	Command DevReadDigi related method
	 * Description:  Read all input and output word and bits of the specified logical 
	 *               device and return the values as a short array (short per bit). 
	 *               Read from the cache.
	 *
	 *	@param argin Logical device
	 *	@returns Array of bit values
	 */
	virtual Tango::DevVarShortArray *dev_read_digi(Tango::DevShort argin);
	virtual bool is_DevReadDigi_allowed(const CORBA::Any &any);
	/**
	 *	Command DevReadNoCacheDigi related method
	 * Description:  Read all input and output word and bits of the specified logical 
	 *               device and return the values as a short array (short per bit). 
	 *               Read from the cache.
	 *
	 *	@param argin Logical device
	 *	@returns Array of bit values
	 */
	virtual Tango::DevVarShortArray *dev_read_no_cache_digi(Tango::DevShort argin);
	virtual bool is_DevReadNoCacheDigi_allowed(const CORBA::Any &any);
	/**
	 *	Command DevGetKeys related method
	 * Description:  Return all the numerical keys known by the server.
	 *
	 *	@returns Numerical keys
	 */
	virtual Tango::DevVarShortArray *dev_get_keys();
	virtual bool is_DevGetKeys_allowed(const CORBA::Any &any);
	/**
	 *	Command DevKey2Name related method
	 * Description:  Return the logical device name associated to a numerical keys 
	 *               name.
	 *
	 *	@param argin Numerical key
	 *	@returns Logical device name
	 */
	virtual Tango::DevString dev_key2_name(Tango::DevShort argin);
	virtual bool is_DevKey2Name_allowed(const CORBA::Any &any);
	/**
	 *	Command DevLog2Hard related method
	 * Description:  Return hardware information of a logical device/logical channel.
	 *
	 *	@param argin [0] : logical device key
	 *	[1] : logical channel
	 *	@returns [0] : offset in wago controller memory (ex: 0x16)
	 *	[1] : MSB=I/O LSB=Bit/Word (ex: 0x4957 = (`I`<<8)+`W`)
	 *	[2] : module reference (ex: 469)
	 *	[3] : module number (1st is 0)
	 *	[4] : physical channel of the module (ex: 1 for the 2nd)
	 */
	virtual Tango::DevVarShortArray *dev_log2_hard(const Tango::DevVarShortArray *argin);
	virtual bool is_DevLog2Hard_allowed(const CORBA::Any &any);
	/**
	 *	Command DevHard2Log related method
	 * Description:  Returns the logical device/logical channel of a memory location 
	 *               on wago controller
	 *
	 *	@param argin [0] : MSB=I/O LSB=Bit/Word (ex: 0x4957 = (`I`<<8)+`W`)
	 *	[1] : offset in wago controller memory (ex: 0x16)
	 *	@returns [0] : logical device key
	 *	[1] : logical channel
	 */
	virtual Tango::DevVarShortArray *dev_hard2_log(const Tango::DevVarShortArray *argin);
	virtual bool is_DevHard2Log_allowed(const CORBA::Any &any);
	/**
	 *	Command DevName2Key related method
	 * Description:  Return the logical device name associated to a numerical keys name.
	 *
	 *	@param argin Logical device name
	 *	@returns Numerical key
	 */
	virtual Tango::DevShort dev_name2_key(Tango::DevString argin);
	virtual bool is_DevName2Key_allowed(const CORBA::Any &any);
	/**
	 *	Command DevWcComm related method
	 * Description:  Executes a command in the wago controller programm. The communication is done using the ISG protocol.
	 *
	 *	@param argin [0] : code of command to execute (ex: 0x010c for ILCK_RESET)
	 *	[1] : 1st parameter
	 *	[2] : 2nd parameter
	 *	etc
	 *	@returns [0] : 1st argout or error code
	 *	[1] : 2nd argout 
	 *	etc
	 */
	virtual Tango::DevVarShortArray *dev_wc_comm(const Tango::DevVarShortArray *argin);
	virtual bool is_DevWcComm_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : Wago::add_dynamic_commands()
	 * Description:  Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(Wago::Additional Method prototypes) ENABLED START -----*/

	void read_scalarAttrPhysValue(Tango::Attribute &att);
	void write_scalarAttrPhysValue(Tango::WAttribute &att);
	bool is_scalarAttrPhysValue_allowed(Tango::AttReqType ty);

	void read_spectAttrPhysValue(Tango::Attribute &att);
	void write_spectAttrPhysValue(Tango::WAttribute &att);
	bool is_spectAttrPhysValue_allowed(Tango::AttReqType ty);

protected:
	Tango::DeviceProxy* modbusDevProxyObj; // Pointer to interface object to Modbus server.

//	Additional Method prototypes

	// structure for buffering value for scalar dynamic attribute.
	typedef struct scallarAttribBuf_t{
		unsigned short key;	// numerical key of related logical device.
		float value;	// buffer for value.
	}scallarAttribBuf_t;

	// structure for buffering values for spectrum dynamic attribute.
	typedef struct spectrumAttribBuf_t{
		unsigned short key;	// numerical key of related logical device.
		vector<float> values; // buffer for values.
	}spectrumAttribBuf_t;

	map<string, scallarAttribBuf_t> scallarAttributeValues; // Mapping of scalar attribute names into logical devices.
	map<string, spectrumAttribBuf_t> spectrumAtributeValues; // Mapping of spectrum attribute names into logical devices.

/*----- PROTECTED REGION END -----*/	//	Wago::Additional Method prototypes
};

/*----- PROTECTED REGION ID(Wago::Additional Classes Definitions) ENABLED START -----*/

/*! Class for dynamic attributes returning a scallar values
 *
 */
class WagoScalarAttrib: public Tango::Attr
{
	public:
	WagoScalarAttrib(const char *name,long data_type,Tango::AttrWriteType w_type)
			      :Attr(name,data_type,w_type) {};
	~WagoScalarAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	                 {(static_cast<Wago *>(dev))->read_scalarAttrPhysValue(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		             {(static_cast<Wago *>(dev))->write_scalarAttrPhysValue(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Wago *>(dev))->is_scalarAttrPhysValue_allowed(ty);}

};

/*! Class for dynamic attributes returning a spectrum values
 *
 */
class WagoSpectAttrib: public Tango::SpectrumAttr
{
	public:
	WagoSpectAttrib(const char *name,long data_type,Tango::AttrWriteType w_type, long max_x)
			      :SpectrumAttr(name,data_type,w_type,max_x) {};
	~WagoSpectAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	                 {(static_cast<Wago *>(dev))->read_spectAttrPhysValue(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	                 {(static_cast<Wago *>(dev))->write_spectAttrPhysValue(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Wago *>(dev))->is_spectAttrPhysValue_allowed(ty);}
};
//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	Wago::Additional Classes Definitions

}	//	End of namespace

#endif   //	Wago_H
