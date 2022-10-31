<?php
require "db.php";

$query = mysqli_query($con, "SELECT * FROM waterLevel ORDER BY Date DESC LIMIT 5");
	while($row = mysqli_fetch_array($query)){

		$ID = $row['ID'];
		$Date = $row['Date'];
		$tankID = $row['tankID'];
		$waterLevel = $row['waterLevel'];
 ?>
			<table style= "border: 1 px solid; border-color:  rgb(0, 0, 0);">
                <tr>
                    <th>ID</th>
                    <th>Date</th>
                    <th>tankID</th>
                    <th>waterLevel</th>
                </tr>
				<tr>
					<td style= "text-align: center;"><?php echo $ID; ?></td>
					<td style= "text-align: center;"><?php echo $Date; ?></td>
					<td style= "text-align: center;"><?php echo $tankID; ?></td>
					<td style= "text-align: center;"><?php echo $waterLevel; ?></td>
				</tr>
            </table>

<?php }
?>
</table>