<?php
$plugin = array(
  'label' => 'Bean',
  'handler' => array(
    'class' => 'EntityCRUDUIBean',
  ),
);

class EntityCRUDUIBean extends EntityCRUDUIBase {

  public function __construct() {
    parent::__construct('bean');
  }

  public function initializeEntity(&$entity) {
    $entity->label = '';
    $entity->title = '';
    $entity->view_mode = 'default';
  }

  public function getPropertyFields($entity) {
    $info = entity_get_info('bean');
    $modes = array();
    foreach ($info['view modes'] as $key => $mode) {
      $modes[$key] = $mode['label'];
    }
    $form = array(
      'label' => array(
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#required' => TRUE,
        '#maxlength' => 255,
        '#description' => t('Name that displays in the admin interface'),
        '#default_value' => $entity->label,
      ),
      'view_mode' => array(
        '#type' => 'select',
        '#title' => t('View Mode'),
        '#required' => TRUE,
        '#options' => $modes,
        '#default_value' => $entity->view_mode,
      ),
      'title' => array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#required' => TRUE,
        '#maxlength' => 255,
        '#description' => t('The title of the block'),
        '#default_value' => $entity->title,
      ),
    );
    return $form;
  }

  public function propertyAttach(&$entity, $form, &$form_state) {
    $entity->label = $form_state['values']['label'];
    $entity->view_mode = $form_state['values']['view_mode'];
    $entity->title = $form_state['values']['title'];
    parent::propertyAttach($entity, $form, $form_state);
  }

  public function presave(&$entity) {

  }
}