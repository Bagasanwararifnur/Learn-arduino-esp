<?php
$servername = "my_servername";
$username = "my_username";
$password = "my_password";
$dbname = "my_database";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$val = $_GET['val'];

$sql = "INSERT INTO dumpvalue (val) VALUES ('$val')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
