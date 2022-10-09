<template>
  <div id="sidebar">
    <div class="inner">
      <div class="contents item active">
        <span>文章目录</span>
      </div>

      <div class="panels">
        <div class="inner">
          <div class="contents panel pjax active" data-title="文章目录">
            <ol class="toc">
              <li
                class="toc-item toc-level-1 active current"
                v-for="(item, index) in sideIndex"
                :key="item"
              >
                <a class="toc-link" href="#">
                  <span class="toc-number">{{ index + 1 }}.</span>
                  <span class="toc-text">{{ item }}</span>
                </a>
              </li>
            </ol>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>
<script setup>
import { defineProps } from "vue";
</script>
<style scoped lang='scss'>
.sidebar {
  box-shadow: 0 1.25rem 1rem 0.3125rem var(--body-bg-shadow);
}
.panels {
  min-height: 50vh;
}
</style>