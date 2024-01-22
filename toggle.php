<?php
include "db.php";

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $state = $conn->real_escape_string($_POST['state'] ?? 'off');
    
    $sql = "UPDATE toggle_state SET state = '$state' WHERE id = 1"; 
    if ($conn->query($sql) === TRUE) {
        echo $state;
    } else {
        echo "Error updating record: " . $conn->error;
    }
} else {
    $sql = "SELECT state FROM toggle_state WHERE id = 1"; 
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        echo $row['state'];
    } else {
        echo "off"; 
    }
}

$conn->close();
