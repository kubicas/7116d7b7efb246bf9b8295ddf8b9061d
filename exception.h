#ifndef INTF_EXCEPTION__EXCEPTION_H
#define INTF_EXCEPTION__EXCEPTION_H
#include <sstream>
#include <stdexcept>

#if _MSC_VER
#define FILE_LINE( E ) __FILE__ << '(' << __LINE__ << "): error " #E ": "
// when ide_filter is finished replace above line with line below
// #define FILE_LINE( E ) "(" __FILE__  ")(" #__LINE__ "): error " #E ": "
#else
#error Unsupported compiler
#endif
#define THROW( E, T ) throw E(dynamic_cast<std::stringstream*>(&(std::stringstream() << FILE_LINE(exception) T))->str())
#define THROW_INVALID_ENUM( E, T ) THROW( E, << "Invalide enum value for '" << #T << "'" )

#endif // INTF_EXCEPTION__EXCEPTION_H