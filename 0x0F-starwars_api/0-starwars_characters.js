#!/usr/bin/node

const axios = require('request');
const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

axios(url, async function(error, response, body) {
    if (error) {
        console.log(error);
    } else {
        const characters = JSON.parse(body).characters;
        for (const character of characters) {
            const res = await new Promise((resolve, reject) => {
                axios(character, (error, res, html) => {
                    if (error) {
                        reject(error);
                    } else {
                        resolve(JSON.parse(html).name);
                    }
                });
            });
            console.log(res);
        }
    }
});