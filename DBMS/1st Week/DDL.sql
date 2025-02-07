-- Create a table Artists with columns artist_id, name, genre, country, biography and record_label.
CREATE TABLE Artists (
    artist_id INT PRIMARY KEY AUTO_INCREMENT
    ,name VARCHAR(100)
    ,genre VARCHAR(50)
    ,country VARCHAR(50)
    ,biography TEXT
    ,record_label VARCHAR(100)
);

-- Create a table Songs with columns song_id, title, artist_id, duration, and release_date.
CREATE TABLE Songs (
    song_id INT PRIMARY KEY AUTO_INCREMENT
    ,title VARCHAR(100)
    ,artist_id INT
    ,duration TIME
    ,release_date DATE
    ,FOREIGN KEY (artist_id) REFERENCES Artists(artist_id)
);

-- Alter table Artists and add the column monthly_listeners.
ALTER TABLE Artists ADD COLUMN monthly_listeners INT;

-- Drop the column monthly_listeners from Artists table.
ALTER TABLE Artists DROP COLUMN monthly_listeners;

-- Create a dummy table.
CREATE TABLE dummy (dummy_number int);

-- Drop the dummy table.
DROP TABLE dummy;

-- Truncate the Songs table.
TRUNCATE Songs;

-- Rename the table Songs to song_table
RENAME TABLE Songs TO song_table;
