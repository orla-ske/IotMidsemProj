<?php

require "db.php";

$waterLevel = $_GET['waterLevel'];
$tankID = $_GET['tankID'];

$sql = "INSERT INTO waterLevel (waterLevel, tankID) VALUES ('{$waterLevel}', '{$tankID}')";

if(mysqli_query($con, $sql))
    echo "New record created successfully";
else
    echo "Failed";

?>
