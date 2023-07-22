#include "element.h"


//Element class implementation.

//Private

QString Element::getLocationXToQString()
{
	return QString::number(locationX);
}

QString Element::getLocationYToQString()
{
	return QString::number(locationY);
}

//Public

Element::Element()
{

}

Element::Element(int currentX, int currentY)
{
	locationX = currentX;
	locationY = currentY;
}

int Element::getLocationX() const
{
	return locationX;
}

void Element::setLocationX(int newLocationX)
{
	locationX = newLocationX;
}

int Element::getLocationY() const
{
	return locationY;
}

void Element::setLocationY(int newLocationY)
{
	locationY = newLocationY;
}

QString Element::locationToQString()
{
	QString locationQString = "";
	locationQString.append(getLocationXToQString());
	locationQString.append(",");
	locationQString.append(getLocationYToQString());
	return locationQString;
}


//Text class implementation.


Text::Text(int newLocationX, int newLocationY, QString newReadableText, QFont newFont)
{
	locationX = newLocationX;
	locationY = newLocationY;
	readableText = newReadableText;
	editableX = locationX + fontSize;
	editableY = locationY + fontSize;
	font = newFont;
}

int Text::getEditableX() const
{
	return editableX;
}

void Text::setEditableX(int newEditableX)
{
	editableX = newEditableX;
}

int Text::getEditableY() const
{
	return editableY;
}

void Text::setEditableY(int newEditableY)
{
	editableY = newEditableY;
}

int Text::getFontSize() const
{
	return fontSize;
}

void Text::setFontSize(int newFontSize)
{
	fontSize = newFontSize;
}

QString Text::getReadableText() const
{
	return readableText;
}

void Text::setReadableText(const QString& newReadableText)
{
	readableText = newReadableText;
}

QFont Text::getFont() const
{
	return font;
}

void Text::setFont(const QFont newFont)
{
	font = newFont;
}

QString Text::toQString()
{
	QString textQString = "Text";
	textQString.append(",");
	textQString.append(locationToQString());
	textQString.append(",");
	textQString.append(readableText);
	textQString.append(",");
	textQString.append(font.toString());
	return textQString;
}

QString Text::toQStringForSave()
{
	QString saveTextQString = locationToQString();
	saveTextQString.append(",");
	saveTextQString.append(readableText);
	saveTextQString.append(",");
	saveTextQString.append(font.toString());
	return saveTextQString;
}


//NamedElement class implementation.


NamedElement::NamedElement()
{

}

bool NamedElement::getNamed() const
{
	return text == nullptr ? false : true;
}

std::shared_ptr<Text> NamedElement::getText()
{
	return text;
}

void NamedElement::setText(std::shared_ptr<Text> &newText)
{
	text = newText;
}

QString NamedElement::toQString()
{
	QString namedElementQString = "NamedElement";
	namedElementQString.append(",");
	namedElementQString.append(locationToQString());
	if(getNamed())
	{
		namedElementQString.append(",");
		namedElementQString.append(text->toQString());
	}
	return namedElementQString;

}


//NamedLocation class implementation.


NamedLocation::NamedLocation(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	text = nullptr;
}

QString NamedLocation::toQString()
{
	QString namedLocationQString = "NamedLocation";
	namedLocationQString.append(",");
	namedLocationQString.append(locationToQString());
	if(getNamed())
	{
		namedLocationQString.append(",");
		namedLocationQString.append(text->toQString());
	}
	return namedLocationQString;
}

QString NamedLocation::toQStringForSave()
{
	QString saveNamedLocationQString = locationToQString();
	if(getNamed())
	{
		saveNamedLocationQString.append(",");
		saveNamedLocationQString.append(text->getReadableText());
	}
	return saveNamedLocationQString;
}


//Concourse class implementation.


Concourse::Concourse(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	text = nullptr;

}

QString Concourse::toQString()
{
	QString concourseQString = "Concourse";
	concourseQString.append(",");
	concourseQString.append(locationToQString());
	if(getNamed())
	{
		concourseQString.append(",");
		concourseQString.append(text->toQString());
	}
	return concourseQString;
}

QString Concourse::toQStringForSave()
{
	QString saveConcourseQString = locationToQString();
	if(getNamed())
	{
		saveConcourseQString.append(",");
		saveConcourseQString.append(text->getReadableText());
	}
	return saveConcourseQString;
}


//Parapet class implementation.


Parapet::Parapet(ParapetType newParapetType, int newLocationX, int newLocationY)
{
	parapetType = newParapetType;
	locationX = newLocationX;
	locationY = newLocationY;
}

ParapetType Parapet::getParapetType() const
{
	return parapetType;
}

void Parapet::setParapetType(const ParapetType &newParapetType)
{
	parapetType = newParapetType;
}

QString Parapet::parapetTypeToQString()
{
	QString parapetTypeQString;
	switch (parapetType)
	{
	case ParapetType::PARAPET1:
        parapetTypeQString = "P1";
		break;
	case ParapetType::PARAPET2:
        parapetTypeQString = "P2";
		break;
	case ParapetType::PARAPET3:
        parapetTypeQString = "P3";
		break;
	case ParapetType::PARAPET4:
        parapetTypeQString = "P4";
		break;
	case ParapetType::PARAPET5:
        parapetTypeQString = "P5";
		break;
	case ParapetType::PARAPET6:
        parapetTypeQString = "P6";
		break;
	case ParapetType::PARAPET7:
        parapetTypeQString = "P7";
		break;
	case ParapetType::PARAPET8:
        parapetTypeQString = "P8";
		break;
	case ParapetType::PARAPET9:
        parapetTypeQString = "P9";
		break;
	case ParapetType::PARAPET10:
        parapetTypeQString = "P10";
		break;
	case ParapetType::PARAPET11:
        parapetTypeQString = "P11";
		break;
	case ParapetType::PARAPET12:
        parapetTypeQString = "P12";
		break;
	case ParapetType::PARAPET13:
        parapetTypeQString = "P13";
		break;
	case ParapetType::PARAPET14:
        parapetTypeQString = "P14";
		break;
	case ParapetType::PARAPET15:
        parapetTypeQString = "P15";
		break;
	case ParapetType::PARAPET16:
        parapetTypeQString = "P16";
		break;
	case ParapetType::PARAPET17:
        parapetTypeQString = "P17";
		break;
	case ParapetType::PARAPET18:
        parapetTypeQString = "P18";
		break;
	case ParapetType::PARAPET19:
        parapetTypeQString = "P19";
		break;
	case ParapetType::PARAPET20:
        parapetTypeQString = "P20";
		break;
	case ParapetType::PARAPET21:
        parapetTypeQString = "P21";
		break;
	case ParapetType::PARAPET22:
        parapetTypeQString = "P22";
		break;
	case ParapetType::PARAPET23:
        parapetTypeQString = "P23";
		break;
	case ParapetType::PARAPET24:
        parapetTypeQString = "P24";
		break;
	case ParapetType::PARAPET25:
        parapetTypeQString = "P25";
		break;
	case ParapetType::PARAPET26:
        parapetTypeQString = "P26";
		break;
	case ParapetType::PARAPET27:
        parapetTypeQString = "P27";
		break;
	case ParapetType::PARAPET28:
        parapetTypeQString = "P28";
		break;
	}
	return parapetTypeQString;
}

QString Parapet::toQString()
{
	QString parapetQString = "Parapet";
	parapetQString.append(",");
	parapetQString.append(parapetTypeToQString());
	parapetQString.append(",");
	parapetQString.append(locationToQString());
	return parapetQString;
}

QString Parapet::toQStringForSave()
{
	QString saveParapetQString = parapetTypeToQString();
	saveParapetQString.append(",");
	saveParapetQString.append(locationToQString());
	return saveParapetQString;
}
