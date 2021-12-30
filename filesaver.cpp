#include "filesaver.h"

Filesaver::Filesaver(QString newPath)
{
	path = newPath;
}

bool Filesaver::saveRailwayAs(Map *map)
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
			QTextStream writer(&file);
			std::vector<QString> toWrite = prepareFileContentToWrite(map);
			for (int i=0; i<toWrite.size(); i++)
			{
				writer << toWrite[i];
			}
			return true;
		}
	}
}

std::vector<QString> Filesaver::prepareFileContentToWrite(Map *map)
{
	std::vector<QString> toSave(0);
	toSave.push_back("StraightTrack\n");
	toSave.push_back(map->straightTrackListToQStringForSaving());
	toSave.push_back("DirectedTrack\n");
	toSave.push_back(map->directedTrackListToQStringForSaving());
	toSave.push_back("CurvedTrack\n");
	toSave.push_back(map->curvedTrackListToQStringForSaving());
	toSave.push_back("LinkedTrack\n");
	toSave.push_back(map->linkedTrackListToQStringForSaving());
	return toSave;
}



