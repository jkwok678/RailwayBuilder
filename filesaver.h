#ifndef FILESAVER_H
#define FILESAVER_H

#include <QString>

class Filesaver
{

private:
	QString path;
public:
	Filesaver(QString newPath);
	bool saveRailwayAs();
};

#endif // FILESAVER_H
