// Base on boost::asio library.
// To judge the address is private address or not
// Return true if the target is private address

#include <boost/asio.hpp>

bool is_private_internal_string( const std::string &ip )
{
	is_private_internal(boost::asio::ip::address_v4::from_string(ip).to_ulong());
}

bool is_private_internal( const uint32_t ip )
{
	if( (ip >> 24) == 0x0A )
	{	// 10.0.0.0 ~ 10.255.255.255
		std::cout << " found in {10.0.0.0 ~ 10.255.255.255}\n";
		return true;
	}
	else if ((ip>>20) == (0xAC1) )	
	{	// 172.16.0.0 ~ 172.31.255.255
		std::cout << " found in {172.16.0.0 ~ 172.31.255.255}\n";
		return true;
	}
	else if( (ip>>16) == 0xC0A8)
	{	// 192.168.0.0 ~ 192.168.255.255
		std::cout << " found in {192.168.0.0 ~ 192.168.255.255}\n";
		return true;
	}
	else
	{
		std::cout << " public address !\n";
		return true;
	}
}

int main(int argc, char* argv[])
{
  // test case.
	const std::string test_ip_1("192.168.30.222");
	const std::string test_ip_2("173.22.244.21");
	const std::string test_ip_3("192.168.0.106");
	const std::string test_ip_4("210.22.36.42");
	const std::string test_ip_5("10.22.33.44");
	const std::string test_ip_6("127.0.0.1");

	const uint32_t test_ip_ulong_1 = boost::asio::ip::address_v4::from_string(test_ip_1).to_ulong();
	const uint32_t test_ip_ulong_2 = boost::asio::ip::address_v4::from_string(test_ip_2).to_ulong();
	const uint32_t test_ip_ulong_3 = boost::asio::ip::address_v4::from_string(test_ip_3).to_ulong();
	const uint32_t test_ip_ulong_4 = boost::asio::ip::address_v4::from_string(test_ip_4).to_ulong();
	const uint32_t test_ip_ulong_5 = boost::asio::ip::address_v4::from_string(test_ip_5).to_ulong();
	const uint32_t test_ip_ulong_6 = boost::asio::ip::address_v4::from_string(test_ip_6).to_ulong();

	std::cout << test_ip_1 << " = " << test_ip_ulong_1 << " ";
	is_private_internal(test_ip_ulong_1);
	std::cout << test_ip_2 << " = " << test_ip_ulong_2 << " ";
	is_private_internal(test_ip_ulong_2);
	std::cout << test_ip_3 << " = " << test_ip_ulong_3 << " ";
	is_private_internal(test_ip_ulong_3);
	std::cout << test_ip_4 << " = " << test_ip_ulong_4 << " ";
	is_private_internal(test_ip_ulong_4);
	std::cout << test_ip_5 << " = " << test_ip_ulong_5 << " ";
	is_private_internal(test_ip_ulong_5);
	std::cout << test_ip_6 << " = " << test_ip_ulong_6 << " ";
	is_private_internal(test_ip_ulong_6);
}
