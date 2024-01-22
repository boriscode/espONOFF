<?php
include 'db.php';
$sql = "SELECT state FROM toggle_state WHERE id = 1"; // assuming id = 1 for simplicity
$result = $conn->query($sql);

$response = array();

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        $response['state'] = $row['state'];
    }
} else {
    // Default state if no record is found
    $response['state'] = 'OFF';
}

// Set header to return JSON
header('Content-Type: application/json');
echo json_encode($response);

$conn->close();
