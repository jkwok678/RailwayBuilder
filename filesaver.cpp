#include "filesaver.h"

Filesaver::Filesaver(QString newPath)
{
	path = newPath;
}

bool Filesaver::saveRailwayAs(Map map)
{

	if (path.isEmpty())
	{
		//Show error message
		return false;
	}
	else
	{
		QFile file (path);
		if (!file.open(QIODevice::WriteOnly))
		{
			//Show error message
			return false;
		}
		else
		{

		}
	}
}

bool Filesaver::createQStringToWrite(Map map)
{

}
