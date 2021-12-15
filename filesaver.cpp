#include "filesaver.h"

Filesaver::Filesaver(QString newPath)
{
	path = newPath;
}

bool Filesaver::saveRailwayAs(Map map)
{

	if (path.isEmpty())
	{
		return false;
	}
	else
	{
		QFile file (path);
		if (!file.open(QIODevice::WriteOnly))
		{
		return false;
		}
		else
		{

		}
	}
}
