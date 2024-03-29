#include "filesaver.h"

//private

std::vector<QString> Filesaver::prepareFileContentToWrite(Map *map)
{
	std::vector<QString> toSave(0);
	toSave.push_back("Text\n");
	toSave.push_back(map->textListToQStringForSaving());
	toSave.push_back("StraightTrack\n");
	toSave.push_back(map->straightTrackListToQStringForSaving());
	toSave.push_back("DirectedTrack\n");
	toSave.push_back(map->directedTrackListToQStringForSaving());
	toSave.push_back("CurvedTrack\n");
	toSave.push_back(map->curvedTrackListToQStringForSaving());
	toSave.push_back("LinkedTrack\n");
	toSave.push_back(map->linkedTrackListToQStringForSaving());
	toSave.push_back("ExitTrack\n");
	toSave.push_back(map->exitTrackListToQStringForSaving());
	toSave.push_back("BufferTrack\n");
	toSave.push_back(map->bufferTrackListToQStringForSaving());
	toSave.push_back("SignalTrack\n");
	toSave.push_back(map->signalTrackListToQStringForSaving());
	toSave.push_back("BridgeUnderpassTrack\n");
	toSave.push_back(map->bridgeUnderpassTrackListToQStringForSaving());
	toSave.push_back("SwitchTrack\n");
	toSave.push_back(map->switchTrackListToQStringForSaving());
	toSave.push_back("CrossoverTrack\n");
	toSave.push_back(map->crossoverTrackListToQStringForSaving());
	toSave.push_back("FlyoverTrack\n");
	toSave.push_back(map->flyoverTrackListToQStringForSaving());
	toSave.push_back("NamedLocation\n");
	toSave.push_back(map->namedLocationListToQStringForSaving());
	toSave.push_back("Concourse\n");
	toSave.push_back(map->concourseListToQStringForSaving());
	toSave.push_back("Parapet\n");
	toSave.push_back(map->parapetListToQStringForSaving());
	return toSave;
}

//Public

Filesaver::Filesaver()
{
	lastSavedPath = "";
}

void Filesaver::setNewFilePath(QString newPath)
{
	lastSavedPath = newPath;
}

bool Filesaver::saveRailway(Map *map)
{

	if (lastSavedPath.isEmpty())
	{
		//Show error message
		return false;
	}
	else
	{
		QFile file (lastSavedPath);
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





