#ifndef FILESAVER_H
#define FILESAVER_H

#include <QFile>
#include <QString>
#include "map.h"

class Filesaver
{

private:
	QString lastSavedPath;

	/**
	 * @brief Make the content that will be written to file.
	 * @param map The current map.
	 * @return A vector of QStrings that contain the text to write.
	 */
    std::vector<QString> prepareFileContentToWrite(std::shared_ptr<Map> map);

public:

	/**
	 * @brief Filesaver default constructor.
	 */
	Filesaver();

	/**
	 * @brief Set a new file path for the filesaver.
	 * @param newPath QString path.
	 */
    void setNewFilePath(QString newPath);

	/**
	 * @brief Save the railway to a file.
	 * @param map The current map on screen.
	 * @return true if it saved, false if it failed to save.
	 */
    bool saveRailway(std::shared_ptr<Map> map);


};

#endif // FILESAVER_H
