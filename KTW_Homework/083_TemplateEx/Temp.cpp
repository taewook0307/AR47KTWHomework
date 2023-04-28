#include "Temp.h"

// cpp파일 내에서의 DataType은 h파일 내 DataType과는 다름
template<typename DataType>
void Temp<DataType>::Function(DataType _Data)
{
	DataType type = _Data;

	std::cout << _Data << std::endl;
}

// template문법은 내부에서만 유효
// void Temp<DataType>::Function(DataType _Data)
// {
//     DataType type = _Data;
// 
//     std::cout << _Data << std::endl;
// }