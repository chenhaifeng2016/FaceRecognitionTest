#ifndef _SERIAL_COM_H_
#define _SERIAL_COM_H_

#include <string>
#include <boost/asio.hpp>

class SerialCom
{
public:
	SerialCom();
	~SerialCom();

	bool OpenPort(std::string port);
	bool OpenPort(int port);
	void ClosePort();
	bool Send(unsigned char* data, int data_len);
	bool Recv(unsigned char* data, int need_read, int* actual_read);

private:
	boost::asio::io_service ios;
	boost::asio::serial_port *serial;
	boost::system::error_code ec;
};

#endif
