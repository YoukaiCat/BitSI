### BiTSI
### Distributed BitTorrent Search Index

Распределённый поисковый индекс в сети битторрент.
Название торрента, имена файлов и метаинформация хешируются и размещаются в сети DHT, на ноде близкой к хешу по id. При поисковом запросе хешируется строка, затем запрашиваются информация о торренте и магнет-ссылка с ноды близкой по id к хешу.
Разделяемая библиотека, плагины для торрент-клиентов, консольные утилиты для тестирования.
Проект вдохновлён идеей плагина Qubit для Vuze.
