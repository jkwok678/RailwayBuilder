#include "map.h"

Map::Map()
{

}

int Map::getTotalTrack() const
{
	return totalTrack;
}

void Map::setTotalTrack(int newTrackTotal)
{
	totalTrack = newTrackTotal;
}

bool Map::checkElementExists(int locationX, int locationY)
{
	bool found = false;
	if (!straightTrackList.empty())
	{
		for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!directTrackList.empty() && found == false)
	{
		for (std::shared_ptr<DirectedTrack>& currentElement : directTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!curvedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CurvedTrack>& currentElement : curvedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!linkedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<LinkedTrack>& currentElement : linkedTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!exitTrackList.empty() && found == false)
	{
		for (std::shared_ptr<ExitTrack>& currentElement : exitTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!bufferTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!signalTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!bridgeUnderpassTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!switchTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}
	if (!crossoverTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CrossoverTrack>& currentElement : crossoverTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!flyoverTrackList.empty() && found == false)
	{
		for (std::shared_ptr<FlyoverTrack>& currentElement : flyoverTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!namedLocationList.empty() && found == false)
	{
		for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}

	if (!concourseList.empty() && found == false)
	{
		for (std::shared_ptr<Concourse>& currentElement : concourseList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}
	if (!parapetList.empty() && found == false)
	{
		for (std::shared_ptr<Parapet>& currentElement : parapetList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				found = true;
			}
		}
	}
	return found;
}

bool Map::checkTextExists(int locationX, int locationY)
{
	bool found = false;
	if (!textList.empty())
	{
		for (std::shared_ptr<Text>& currentText : textList)
		{
			int textCurrentX = currentText->getLocationX();
			int textCurrentY = currentText->getLocationY();
			int textEditableX = currentText->getEditableX();
			int textEditableY = currentText->getEditableY();
			if (locationX >= textCurrentX && locationX <=textEditableX)
			{
				if (locationY >= textCurrentY && locationY <= textEditableY)
				{
				found = true;
				}
			}
		}
	}
	return found;
}

//StraightTrack related methods


std::vector<std::shared_ptr<StraightTrack> > Map::getStraightTrackList() const
{
	return straightTrackList;
}

void Map::setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> >& newSignalTrackList)
{
	straightTrackList = newSignalTrackList;
}

void Map::addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack)
{
	int tempLocationX = newStraightTrack->getLocationX();
	int templocationY = newStraightTrack->getLocationY();
	if (!checkElementExists(tempLocationX, templocationY))
	{
		straightTrackList.push_back(newStraightTrack);
		++totalTrack;
	}
	else
	{
		//Show error if an element already exists there.
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<StraightTrack> Map::getStraightTrackAt(int locationX, int locationY)
{
	std::shared_ptr<StraightTrack> straightTrack = nullptr;
	if (!straightTrackList.empty())
	{
		//Loop through all the straight tracks to see if one exists at these coordiantes.
		for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
		{
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentX == locationX && currentY == locationY)
			{
				straightTrack = currentElement;
				break;
			}
		}
	}
	return straightTrack;
}
