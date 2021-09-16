
CREATE TABLE Crawler.Websites (
                                  id INT NOT NULL AUTO_INCREMENT,
                                  domain VARCHAR(1000) UNIQUE NOT NULL,
                                  homepage varchar(1000) UNIQUE NOT NULL,
                                  lastTime TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NOT NULL,
                                  PRIMARY KEY(id)
)