import fetch from 'isomorphic-unfetch';

const apiUrl = process.env.API_URL + ':' + process.env.PORT;

export const fetchListings = async () => fetch(`${apiUrl}/api/listings`);
