#pragma once
#include <string>

class MovieData
{
private:
	std::string title;
	std::string imdbId;
	std::string plot;
	unsigned lengthMin = 0;

public:
	MovieData() {}
	MovieData(std::string title, std::string imdbId, std::string plot, unsigned lengthMin) : title(title), imdbId(imdbId), plot(plot), lengthMin(lengthMin) {}
	virtual ~MovieData() {};

	std::string GetTitle() { return title; }
	std::string GetImdbId() { return imdbId; }
	std::string GetPlot() { return plot; }
	unsigned GetLengthMin() { return lengthMin; }
};

