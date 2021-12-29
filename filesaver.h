#ifndef FILESAVER_H
#define FILESAVER_H

#include <QFile>
#include <QString>
#include "map.h"

class Filesaver
{

private:
	QString path;
public:
	Filesaver(QString newPath);
	bool saveRailwayAs(Map map);
	std::vector<QString> prepareFileContentToWrite(Map map);
};

#endif // FILESAVER_H
