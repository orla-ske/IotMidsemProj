<?php
require "db.php";


    if (!isset($_GET['tankID'])) 
        die(" tankID not specified");
    if ($_GET['tankID']=='')
        die(" tankID is blank");
    if (!is_numeric($_GET['tankID'] ) )
        die(" tankID is not numeric");
    
    $data=array();        

    $q=mysqli_query($con,"select * from waterLevel where tankID={$_GET['tankID']} ORDER BY Date DESC LIMIT 1");    
    
    $row=mysqli_fetch_object($q);

    while ($row)
    {         
        echo "ID: ";
        echo " {$row->tankID}\n";
        echo "Current Water Level: ";
        echo "{$row->waterLevel}";
        echo " cm\n";
        $row=mysqli_fetch_object($q);
    }       
    


?>