# ESP32 demo relay in php
## Overview

this project demonstrates how to control a relay using an esp32 through a simple php server. the php server returns a json object indicating the state of the relay (on or off), which the esp32 reads and processes to control the relay accordingly.
## Components

Esp32 module
Relay module

## ESP32 Setup

Relay Connection: Connect the relay's input (IN) pin to the ESP33's digital pin 5.

## Server Setup

Database: Run the following SQL command to create the required database table:

   ``` sql
    CREATE TABLE toggle_state (
        id INT AUTO_INCREMENT PRIMARY KEY,
        state VARCHAR(10) NOT NULL
    );
   ```

Database Connection: Update `db.php` with your database connection credentials.
Get State: The `get_state.php` script returns the current state of the relay in JSON format.
Toggle State: `The toggle.php` script updates the relay's state in the database based on the button press.
ESP Code: The `toggle.ino` file contains the Arduino code to be uploaded to the ESP32.

## Usage

The ESP32 reads the state from the PHP server and controls the relay accordingly.
Use the provided PHP scripts to interact with the database and change the state of the relay.
