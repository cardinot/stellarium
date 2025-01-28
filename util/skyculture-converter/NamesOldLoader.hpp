#pragma once

#include <vector>
#include <iostream>
#include <QMap>
#include <QString>

class NamesOldLoader
{
	QMap<int, std::vector<QString>> starNames;
	QMap<QString/*dsoId*/,std::vector<QString/*name*/>> dsoNames;
	struct PlanetName
	{
		QString english;
		QString native;
	};
	QMap<QString/*planetId*/,std::vector<PlanetName>> planetNames;

	void loadStarNames(const QString& skyCultureDir);
	void loadDSONames(const QString& skyCultureDir);
	void loadPlanetNames(const QString& skyCultureDir);
public:
	void load(const QString& skyCultureDir);
	int/*HIP*/ findStar(QString const& englishName) const;
	QString/*id*/ findPlanet(QString const& englishName) const;
	QString/*id*/ findDSO(QString const& englishName) const;
	bool dumpJSON(std::ostream& s) const;
};
