const jsonFile = './Leaderboard.json';
fetch(jsonFile)
    .then(response => response.json())
    .then(data=>{
        const tableBody = document.querySelector("#leaderboard tbody");
        tableBody.innerHTML = '';
        data.forEach(player => {
            const row = document.createElement('tr');
            row.innerHTML = `
                <td>${player.id}</td>
                <td>${player.name}</td>
                <td>${player.region}</td>
                <td>${player.track}</td>
                <td>${player.class}</td>
                <td>${player.car}</td>
                <td>${player.time}</td>
            `;
            tableBody.appendChild(row);
            
        });
    })
    .catch(error=>{
        console.error('error loading json',error);
    });