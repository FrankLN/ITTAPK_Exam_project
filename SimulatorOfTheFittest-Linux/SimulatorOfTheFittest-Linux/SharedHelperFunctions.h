#ifndef SHARED_HELPER_FUNCTIONS_H
#define SHARED_HELPER_FUNCTIONS_H

namespace myHelper
{
	template<typename DstType, typename SrcType>
	bool IsType(SrcType* src)
	{
		return dynamic_cast<DstType*>(src) != 0;
	}
}

#endif