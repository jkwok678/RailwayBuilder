#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include "map.h"

class FileOperation
{
public:
	FileOperation();

	/**
	 * @brief Save the current layout into a ttb2 file.
	 * @param map A map object
	 */
	bool saveAsttb2(Map map);
};

#endif // FILEOPERATION_H
