import PropTypes from 'prop-types';
import React from 'react';

const ErrorMessage = props => <article>{props.title}</article>;

ErrorMessage.displayname = 'ErrorMessage';

ErrorMessage.propTypes = {
  title: PropTypes.string.isRequired,
};

export default ErrorMessage;
