#ifndef FILESAVER_H
#define FILESAVER_H

#include <QFile>
#include <QString>
#include "map.h"

class Filesaver
{

private:
	static QString lastSavedPath;
public:
	Filesaver();
	Filesaver(QString newPath);
	bool saveRailway(Map *map);
	std::vector<QString> prepareFileContentToWrite(Map *map);
};

#endif // FILESAVER_H
