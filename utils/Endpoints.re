module Endpoints = {};

let fetchListings = () => Fetch.fetch({j|process.env.HOST /api/listings|j});
