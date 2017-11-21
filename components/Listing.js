import PropTypes from 'prop-types';
import React from 'react';

const Listing = props => (
  <article>
    <h3>{props.title}</h3>
    <h4>${props.price}</h4>
  </article>
);

Listing.displayname = 'Listing';

Listing.propTypes = {
  price: PropTypes.string,
  title: PropTypes.string.isRequired,
};

export default Listing;
