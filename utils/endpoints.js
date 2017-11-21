import fetchJsonp from 'fetch-jsonp';

export const fetchListings = () =>
  fetchJsonp(
    `https://openapi.etsy.com/v2/shops/EvergreenRoots/listings/active.js?api_key=${
      __ENV__.etsyApiKey
    }`
  );
