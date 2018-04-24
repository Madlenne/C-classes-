#pragma once

typedef char* Czary;
typedef char** KsiegaCzarow;

void UtworzCzar(const Czary text, Czary* start, Czary* end);
void RzucCzar(Czary start, Czary end);

void DodajCzar(KsiegaCzarow* book, Czary start, Czary end);
void Czytaj(KsiegaCzarow* book);
void SpalKsiege(KsiegaCzarow book);
void ZniszczCzar(Czary start, Czary end);
