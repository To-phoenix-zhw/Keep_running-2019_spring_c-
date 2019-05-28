// concatenating strings
#include <iostream>
#include <string>

int main ()
{
  std::string firstlevel ("com");
  std::string secondlevel ("cplusplus");
  std::string scheme ("http://");
  std::string hostname;
  std::string url;

  hostname = "www." + secondlevel + '.' + firstlevel;
  // 可以直接实现字符串/字符的连接 
  url = scheme + hostname;

  std::cout << url << '\n';

  return 0;
}

	


