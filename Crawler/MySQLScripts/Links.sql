CREATE TABLE Crawler.Links (
                               id INT NOT NULL AUTO_INCREMENT,
                               url varchar(10000) UNIQUE NOT NULL,
                               websiteId INT NOT NULL,
                               status INT NOT NULL,
                               PRIMARY KEY(id)
)